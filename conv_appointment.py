#/usr/bin/env python
#-*- coding: utf-8 -*-


def tranPeriod(period):
	period_list= {'1':0,'2':1,'3':2,'4':3,'Z':4,
			'5':5,'6':6,'7':7,'8':8,'9':9,'A':10,'B':11,'C':12,'D':13}
	return  str(period_list.get(period))

def main():
	fp = open('insert.txt','r')
	fp2 = open('result.txt','w')
	for row in fp:
		if 'INSERT' in row:
			fp2.write(row)
		else:
			end = False
			new_row=''
			tmp = row.split(',')
			for i in range(0,len(tmp)):
				if(i!=4 and i!=7 and i!=8):
					if(i==5 or i==6):
						new_row += tranPeriod(tmp[i][2])
					else:
						new_row += tmp[i]
					if(i!=14 and ';' in tmp[i] == False):
						new_row += ','
			fp2.write(new_row)
	fp.close()
	fp2.close()
				
if  __name__ == '__main__':
	main()

