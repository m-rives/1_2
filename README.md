"UE 1.2" 

First 3 digits either 978 or 979
Exactly 12 digits
Not 2 dashes consecutively
If last dash is missing, it must be added before the calculated check digit is added

X = 1 * x_1 + 2 * x_2 + 3 * x_3 + ... + 12 * x_12
x_13 = X mod 11

if x_13 = 10{
    x_13 = X
    }