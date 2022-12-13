from sympy import *

x = Symbol('x')
expr = x**5 + x**4 + 3*(x**3) + 2*(x**2) + x**1 + 1
pprint(solve(expr, x))