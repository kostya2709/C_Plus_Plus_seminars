import sys
import gc

def show_referrers(obj):
    for ref in gc.get_referrers(obj):
        print(f"Referrer: {ref}")



print("Usual:")
a = [1, 2, 3]
b = a
c = b

print("RefCount: ", sys.getrefcount(a) - 1) 
show_referrers(a)

print("Cycles:")

cycles_a = []
cycles_a.append(cycles_a)
print("RefCount: ", sys.getrefcount(cycles_a) - 1)
print("Referrers: ", len(gc.get_referrers(cycles_a)))

