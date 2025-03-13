class Solution:
    def fib(self, n: int) -> int:
        res = [0, 1]
        for i in range(2, n+1):
            res.append(res[i-1] + res[i-2])
        return res[n]

if __name__ == '__main__':
    n = 5
    sol = Solution()
    print(sol.fib(n))
