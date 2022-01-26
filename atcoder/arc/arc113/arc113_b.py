
def main():
    a, b, c = list(map(int, input().split()))
    n = pow(b, c, 4)
    res = pow(a, n, 10)
    print(res)

# エントリポイント
if __name__ == '__main__':
    main()
