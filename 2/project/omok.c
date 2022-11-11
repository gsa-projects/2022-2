#include "omok.h"
#define SIZE 10

int dols = 0;
stat game = EMPTY;
grid board[SIZE][SIZE];

int main() {
    coord cursor = { SIZE / 2, SIZE / 2 };  // 커서의 위치를 오목판 가운데로 초기화
    char input; // 키 입력 받을 변수
    bool is_bot_turn = false;

    // 오목판 초기화
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].pos.row = i;
            board[i][j].pos.col = j;
            board[i][j].stat = EMPTY;
        }
    }

    print_board(cursor);
    while (true) {
        if (!_kbhit()) continue;    // 키보드 입력을 받을 수 있을 때까지 반복

        input = _getch();
        switch (input) {
        case ARROW:
            input = _getch();

            system("cls");
            cursor_move(&cursor, input);
            print_board(cursor);

            break;
        case ENTER:
            // you
            switch (get_stat(cursor.row, cursor.col)) {
            case BOT:
                system("cls");
                print_board(cursor);

                set_color(BRIGHT_YELLOW);
                printf("\n\n[CMD]");
                set_color(WHITE);
                printf(" Already installed by Bot");
                break;
            case YOU:
                system("cls");
                print_board(cursor);

                set_color(BRIGHT_YELLOW);
                printf("\n\n[CMD]");
                set_color(WHITE);
                printf(" Already installed by You");
                break;
            case EMPTY:
                board[cursor.row][cursor.col].stat = YOU;
                dols++;
                is_bot_turn = true;
                system("cls");
                print_board(cursor);

                set_color(BRIGHT_BLUE);
                printf("\n\n[YOU]");
                set_color(WHITE);
                printf(" installed at (%d, %d)", cursor.row, cursor.col);
                break;
            }

            // bot
            if (is_bot_turn) {
                coord bot = get_bot(cursor);
                board[bot.row][bot.col].stat = BOT;
                is_bot_turn = false;
                //char ip; scanf("%c", &ip); if (ip == 'g')
                {
                    Sleep(1000);
                    system("cls");
                    print_board(cursor);

                    set_color(BRIGHT_RED);
                    printf("\n\n[BOT]");
                    set_color(WHITE);
                    printf(" installed at (%d, %d)", bot.row, bot.col);
                }
            }
            break;
        }
    }
}

coord get_bot(coord cursor) {
    coord ret = { -1, -1 };
    coord row_choice = { -1, -1 };
    coord col_choice = { -1, -1 };
    coord slash_choice = { -1, -1 };
    coord rslash_choice = { -1, -1 };

    // todo: 빈틈 내고 오목 만드는 경우
    // todo: 막아야 하는 경우가 생겨도 자기가 이길 수 있는 경우 무시하고 공격

    bool attack = true;
    int cur_dols = 0;

    // 가로 오목 판정
    cur_dols = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {           
            if (get_stat(i, j) == YOU) {
                cur_dols++;
                int count = 0;
                for (int r = j; r < min(j + 5, SIZE); ++r) {
                    if (get_stat(i, r) == YOU) count++;
                    else break;
                }

                //printf("\nrow_count: %d starts at (%d, %d)", count, i, j);  // DEBUG
                if (count == 5) { // todo: 적어도 한 개의 block이면 4개째부터 막기
                    attack = false;
                    game = YOU;
                    return ret;
                }
                else if (count >= 3) {
                    attack = false;
                    bool is_left_block = (j == 0 || get_stat(i, j - 1) != EMPTY);
                    bool is_right_block = (j == SIZE - count || get_stat(i, j + count) != EMPTY);
                       
                    //printf("\n  - leftblock: %d\n  - rightblock: %d", leftblock, rightblock);   // DEBUG

                    if (!is_left_block && !is_right_block) {
                        row_choice = best_choice(board[i][j - 1].pos, board[i][j + count].pos);
                    }
                    else if (is_left_block && !is_right_block) {
                        if (count >= 4) {
                            set_pos(&row_choice, i, j + count);
                        }
                    }
                    else if (!is_left_block && is_right_block) {
                        if (count >= 4) {
                            set_pos(&row_choice, i, j - 1);
                        }
                    }
                }
            }
            if (cur_dols >= dols) {
                break;
            }
        }
        if (cur_dols >= dols) {
            break;
        }
    }

    // 세로 오목 판정
    cur_dols = 0;
    for (int j = 0; j < SIZE; ++j) {
        for (int i = 0; i < SIZE; ++i) {
            if (get_stat(i, j) == YOU) {
                cur_dols++;
                int count = 0;
                for (int r = i; r < min(i + 5, SIZE); ++r) {
                    if (get_stat(r, j) == YOU) count++;
                    else break;
                }

                //printf("\ncol_count: %d starts at (%d, %d)", count, i, j);  // DEBUG
                if (count == 5) {
                    attack = false;
                    game = YOU;
                    return ret;
                }
                else if (count >= 3) {
                    attack = false;
                    bool is_up_block = (i == 0 || get_stat(i - 1, j) != EMPTY);
                    bool is_down_block = (i == SIZE - count || get_stat(i + count, j) != EMPTY);

                    //printf("\n  - is_up_block: %d\n  - is_down_block: %d", is_up_block, is_down_block);   // DEBUG

                    if (!is_up_block && !is_down_block) {
                        col_choice = best_choice(board[i - 1][j].pos, board[i + count][j].pos);
                    }
                    else if (is_up_block && !is_down_block) {
                        if (count >= 4) {
                            set_pos(&col_choice, i + count, j);
                        }
                    }
                    else if (!is_up_block && is_down_block) {
                        if (count >= 4) {
                            set_pos(&col_choice, i - 1, j);
                        }
                    }
                }
            }
            if (cur_dols >= dols) {
                break;
            }
        }
        if (cur_dols >= dols) {
            break;
        }
    }

    // 슬래쉬 오목 판정 | 왼쪽 아래로 읽기
    cur_dols = 0;
    while (cur_dols < dols) {
        bool find = false;
        int fi, fj;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (get_stat(i, j) == YOU) {
                    cur_dols++;
                    fi = i, fj = j;
                    find = true;
                }
                if (find) break;
            }
            if (find) break;
        }

        if (find) {
            int count = 0;
            for (int i = fi, j = fj; i < SIZE && j >= 0; i++, j--) {
                if (get_stat(i, j) == YOU) count++;
                else break;
            }

            //printf("\ncol_count: %d starts at (%d, %d)", count, i, j);  // DEBUG
            if (count == 5) {
                attack = false;
                game = YOU;
                return ret;
            }
            else if (count >= 3) {
                attack = false;
                bool is_upright_block = ((fi == 0 || fj == SIZE - 1) || get_stat(fi - 1, fj + 1) != EMPTY);
                bool is_downleft_block = ((fi == SIZE - count || fj == count - 1) || get_stat(fi + (count - 1), fj - (count - 1)) != EMPTY);

                //printf("\n  - is_up_block: %d\n  - is_down_block: %d", is_up_block, is_down_block);   // DEBUG

                if (!is_upright_block && !is_downleft_block) {
                    col_choice = best_choice(board[fi - 1][fj + 1].pos, board[fi + (count - 1)][fj - (count - 1)].pos);
                }
                else if (is_upright_block && !is_downleft_block) {
                    if (count >= 4) {
                        set_pos(&col_choice, fi + (count - 1), fj - (count - 1));
                    }
                }
                else if (!is_upright_block && is_downleft_block) {
                    if (count >= 4) {
                        set_pos(&col_choice, fi - 1, fj + 1);
                    }
                }
            }
        }
    }
    
    // 역슬래쉬 오목 판정
    

    // DEBUG
    /*printf("\nattack: %d", attack);
    printf("\nrow_choice: (%d, %d)", row_choice.row, row_choice.col);
    printf("\ncol_choice: (%d, %d)", col_choice.row, col_choice.col);*/

    // 최선의 방어 위치 선택
    if (attack) {
        set_pos(&ret, 1, 1);
    }
    else {
        ret = best_choice(row_choice, col_choice); // best_choice(best_choice(best_choice(row_choice, col_choice), slash_choice), rslash_choice);
    }

    return ret;
}

coord best_choice(coord pos1, coord pos2) {
    return (is_around(pos1) > is_around(pos2)) ? pos1 : pos2;
}

int is_around(coord pos) {
    int cnt = 0;
    for (int i = pos.row - 1; i <= pos.row + 1; ++i)
        for (int j = pos.col - 1; j <= pos.col + 1; ++j)
            cnt += (get_stat(i, j) != EMPTY);
    return cnt - (get_stat(pos.row, pos.col) != EMPTY);
}

int is_around_e(int row, int col) {
    int cnt = 0;
    for (int i = row - 1; i <= row + 1; ++i)
        for (int j = col - 1; j <= col + 1; ++j)
            cnt += (get_stat(i, j) != EMPTY);   
    return cnt - (get_stat(row, col) != EMPTY);
}

stat get_stat(int row, int col) {
    if (row >= SIZE || row < 0) return EMPTY;
    else if (col >= SIZE || col < 0) return EMPTY;
    else return board[row][col].stat;
}

void print_board(coord cursor) {
    int idx;
    char* left[6] = { "└ ", "├ ", "┌ ", "┗ ", "┣ ", "┏ " };
    char* middle[6] = { "┴ ", "┼ ", "┬ ", "┻ ", "╋ ", "┳ " };
    char* right[6] = { "┘ ", "┤ ", "┐ ", "┛ ", "┫ ", "┓ " };

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int iscursor = i == cursor.row && j == cursor.col;

            switch (get_stat(i, j)) {
            case YOU:
                set_color(BRIGHT_BLUE - 8 * iscursor);

                printf(DOL_YOU);
                break;
            case BOT:
                set_color(BRIGHT_RED - 8 * iscursor);

                printf(DOL_BOT);
                break;
            case EMPTY:
                idx = (i == 0) ? 2 : (i == SIZE - 1) ? 0 : 1;
                if (iscursor) idx += 3;

                set_color(GRAY - 1 * iscursor);

                printf("%s", (j != 0 && j != SIZE - 1) ? middle[idx] : (j == 0) ? left[idx] : right[idx]);
                break;
            }
        }
        printf("\n");
    }
}

void cursor_move(coord* cursor, char input) {
    switch (input) {
    case ARROW_UP:
        cursor->row = (cursor->row - 1 + SIZE) % SIZE;
        break;
    case ARROW_LEFT:
        cursor->col = (cursor->col - 1 + SIZE) % SIZE;
        break;
    case ARROW_RIGHT:
        cursor->col = (cursor->col + 1 + SIZE) % SIZE;
        break;
    case ARROW_DOWN:
        cursor->row = (cursor->row + 1 + SIZE) % SIZE;
        break;
    default:
        break;
    }
}

void set_pos(coord* pos, int r, int c) {
    pos->row = r;
    pos->col = c;
}

int random(int a, int b) {
    srand(time(NULL));
    return (rand() % 2 == 0 ? a : b);
}

void go(int row, int col) {
    COORD Pos = { row - 1, col - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void set_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// 겁나 기네
//printf