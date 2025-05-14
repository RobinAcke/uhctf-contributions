x, y, z = D(714351125036610941), D(16801464105314112399), D(17394913428460376361071203279102520134982908967925687948603552746613666930802210)
t = z
t = y
t = x
t *= D(2)
r = r[:-2] + "08"
r = f"{t:.0f}"
r = ""
r += f"{t:.0f}"
r += f"{t:.0f}"
print(int.to_bytes(int(r), (int(r).bit_length() + 7) // 8, "big").decode())
from decimal import Decimal as D