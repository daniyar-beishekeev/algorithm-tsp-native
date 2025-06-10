# /usr/bin/time -f "%U" ./dp < test.in > test.out

TIME_LIMIT = 60
algorithms = [
'primitive',
'dp',
'primitive_optimized'
]

import subprocess
import random

def gen_test(n):
	ans = str(n) + '\n'
	for i in range(n):
		for j in range(n):
			if j > 0:
				ans += ' '
			if i == j:
				ans += '0'
			else:
				ans += str(random.randint(1, 10 ** 9))
		ans += '\n'
	return ans

testlib = dict()
def get_test(n):
	if n not in testlib:
		testlib[n] = gen_test(n)
	return testlib[n]

print('algorithm', 'n', 'time_s', 'output')
for algorithm in algorithms:
	for n in range(1, 26):
		cmd = ['/usr/bin/time', '-f', '%U', './' + algorithm, str(n)]
		test_in = get_test(n)
		result = subprocess.run(
			cmd,
			input=test_in,
			stdout=subprocess.PIPE,
			stderr=subprocess.PIPE,
			text=True
		)
		runtime = float(result.stderr.strip())
		print(algorithm, n, runtime, result.stdout.split('\n')[0])
		if runtime > TIME_LIMIT:
			break