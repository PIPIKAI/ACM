#coding=cp936
# 作者： 钟志锴 序号：34
from operator import add, sub
from random import randint, choice
ops = {'+': add, '-': sub}
MAXTRIES = 2
def doprob():
	op = choice('+-')
	nums = [randint(1,10) for i in range(2)]
	nums.sort(reverse=True)
	ans = ops[op](*nums)
	pr = '%d %s %d = ' % (nums[0], op, nums[1])
	oops = 0
	while True:
		try:
			if int(raw_input(pr)) == ans:
				print '你的答案对了'
				break
			if oops == MAXTRIES:
				print '正确答案是：\n%s%d'%(pr, ans)
			else:
				print '你的答案错了！请重试'
				oops += 1
		except (KeyboardInterrupt,EOFError, ValueError):
			print '不正确的输入，请重试'

def main():
	while True:
		doprob()
		try:
			opt = raw_input('重来吗（输入 n 退出）? [y]').lower()
			if opt and opt[0] == 'n':
				break
		except (KeyboardInterrupt, EOFError):
			break

if __name__ == '__main__':
	main()
