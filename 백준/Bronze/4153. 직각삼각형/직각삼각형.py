while True:
    nums = list(map(int,input().split()))
    c = max(nums)
    if c == 0:
        break
    nums.remove(c)
    if c**2 == nums[0]**2+nums[1]**2:
        print("right")
    else:
        print("wrong")