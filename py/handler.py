import sys
from online_opt_mod import search_test

row = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21]
col = [-9, -6, -3, 0, 1, 2, 3, 4, 5]

if len(sys.argv) != 2:
	print "python handler.py <0: Max Bundle 1: WiFi only, 2: ZigBee only, 3: Bundle, 4: Online Optimization>"
	quit()
f = open("c.dat", "r")
data = f.readline().split()
f.close()
f = open("py.dat", "w")
cmd = int(sys.argv[1])
if cmd == 4:
	(x, y) = search_test(row[int(data[0])+1], col[int(data[1])+1], 
		float(data[2])/100, float(data[3])/100, 
		int(data[4]), int(data[5]), int(data[6]))
	f.write(str(x-1) +" "+ str(y-1))
else:
	highest = [20, 7]
	for idx in range(0, 2):
		if cmd==0:
			f.write(str(highest[idx])+" ")
		elif cmd==3 or (idx==0 and cmd==1) or (idx==1 and cmd==2):
			power = int(data[idx])
			prr = int(data[idx+2])
			step = 2 - idx
########## "ART" power selection ###########
			if (prr < 90) and (power <= highest[idx] - step):
				power += step
			if (prr > 95) and (power >= step):
				power -= step
############################################
			f.write(str(power)+" ")
		else:
			f.write("-1 ")
f.close()
