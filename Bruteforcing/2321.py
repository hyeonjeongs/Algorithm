# 분해합

m = input() 
cnt = 0
list = []

# 브루투포스로 전체 숫자 돌리며, 각 숫자와의 합이 m인것을 배열에 저장하기
for i in range(1, int(m)):
    sum = 0 + i
    num = len(str(i))
    
    for j in range(num):
        sum += int(str(i)[j])  # 현재 int->str 배열로 각자리 숫자 가져온 후 -> int로 변환하여 더하기
        
    if sum == int(m):
        cnt += 1
        list.append(i)
        
if cnt == 0:
    print(0)
else:
    print(min(list))
