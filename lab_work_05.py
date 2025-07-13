'''
Question:
You are supplied a file of large nonrepeating set of truly random key letter. Your job
is to encrypt the plaintext using ONE TIME PAD technique. Then perform the
reverse operation to get original plaintext.
'''

def letter_to_num(c):
    return ord(c.upper()) - ord('A') + 1

def num_to_letter(n):
    n = n - 1 + 26
    return chr((n % 26) + ord('A'))

def otp_encrypt(message, key):
    result = ""
    for m, k in zip(message, key):
        if m.isalpha():
            m_val = letter_to_num(m)
            k_val = letter_to_num(k)
            c_val = (m_val + k_val) % 26
            result += num_to_letter(c_val)
        else:
            result += m
    return result

def otp_decrypt(ciphertext, key):
    result = ""
    for c, k in zip(ciphertext, key):
        if c.isalpha():
            c_val = letter_to_num(c)
            k_val = letter_to_num(k)
            m_val = (c_val - k_val + 26) % 26
            result += num_to_letter(m_val)
        else:
            result += c
    return result

def encrypt_message(message, key_file="i1.txt"):
    with open(key_file, "r") as f:
        key = f.read().strip().upper()

    used_key = key[:len(message)]
    remaining_key = key[len(message):]

    ciphertext = otp_encrypt(message.upper(), used_key)

    with open(key_file, "w") as f:
        f.write(remaining_key)

    return ciphertext

def decrypt_message(ciphertext, key_file="i2.txt"):
    with open(key_file, "r") as f:
        key = f.read().strip().upper()

    used_key = key[:len(ciphertext)]
    remaining_key = key[len(ciphertext):]

    decrypted = otp_decrypt(ciphertext.upper(), used_key)

    with open(key_file, "w") as f:
        f.write(remaining_key)

    return decrypted

if __name__ == "__main__":
    with open("i1.txt", "w") as f:
        f.write("ABCDEFGH")

    with open("i2.txt", "w") as f:
        f.write("ABCDEFGH")

    message = "XYZ"

    cipher = encrypt_message(message)
    print("Encrypted:", cipher)

    decrypted = decrypt_message(cipher)
    print("Decrypted:", decrypted)
