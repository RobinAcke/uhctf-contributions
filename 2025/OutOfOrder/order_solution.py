import itertools

lines = [
    "t = z",
    "t = y",
    "t = x",
    "t *= D(2)",
    "r = r[:-2] + '08'",
    "r = f'{t:.0f}'",
    "r += f'{t:.0f}'",
    "r += f'{t:.0f}'",
]

def try_permutations():
    for perm in itertools.permutations(lines):
        code = f"""
from decimal import Decimal as D
x, y, z = D(714351125036610941), D(16801464105314112399), D(17394913428460376361071203279102520134982908967925687948603552746613666930802210)
r = ""
{perm[0]}
{perm[1]}
{perm[2]}
{perm[3]}
{perm[4]}
{perm[5]}
{perm[6]}
{perm[7]}

print(int.to_bytes(int(r), (int(r).bit_length() + 7) // 8, "big").decode())
"""
        try:
            exec(code)
        except Exception as e:
            pass

try_permutations()