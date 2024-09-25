import ast
import pprint

code = """
def greet(name):
    print("Hello, " + name + "!")
    
greet("Alice")
"""

tree = ast.parse(code)
pprint.pprint(ast.dump(tree))
