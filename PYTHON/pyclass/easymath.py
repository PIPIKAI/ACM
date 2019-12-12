#coding=cp936
# ���ߣ� ��־�� ��ţ�34
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
				print '��Ĵ𰸶���'
				break
			if oops == MAXTRIES:
				print '��ȷ���ǣ�\n%s%d'%(pr, ans)
			else:
				print '��Ĵ𰸴��ˣ�������'
				oops += 1
		except (KeyboardInterrupt,EOFError, ValueError):
			print '����ȷ�����룬������'

def main():
	while True:
		doprob()
		try:
			opt = raw_input('���������� n �˳���? [y]').lower()
			if opt and opt[0] == 'n':
				break
		except (KeyboardInterrupt, EOFError):
			break

if __name__ == '__main__':
	main()
