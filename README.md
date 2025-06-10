## Run in Ubuntu environment
## Tested on WSL Ubuntu Kinetic

```bash
# Allow script execution chmod +x ./compile.sh
# Compile all files via
./compile.sh
```

```bash
python3 benchmark.py
```
Basic python script that produce to its output time consumed for each algorithm (dp, primitive, primitive_optimized) for incremental N until previous reaches defined time limit 60s(default)

## Pre calculated benchmark test, time shown in second(s).
|N|dp|primitive|primitive_optimized|
|-:|:------:|:------:|:------:|
|1|0.000|0.000|0.000|
|2|0.000|0.000|0.000|
|3|0.000|0.000|0.000|
|4|0.000|0.000|0.000|
|5|0.000|0.000|0.000|
|6|0.000|0.000|0.000|
|7|0.000|0.000|0.000|
|8|0.000|0.000|0.000|
|9|0.000|0.020|0.000|
|10|0.000|0.330|0.020|
|11|0.000|3.640|0.200|
|12|0.010|47.800|2.570|
|13|0.030|657.540|33.940|
|14|0.030||348.140|
|15|0.050|||
|16|0.130|||
|17|0.270|||
|18|0.650|||
|19|1.470|||
|20|3.060|||
|21|6.740|||
|22|15.220|||
|23|31.270|||
|24|76.510|||
|25|146.570|||

### RAW data (4th column is for comparing output found by each algorothim)
```
algorithm n time_s output
primitive 1 0.0 0
primitive 2 0.0 1409702067
primitive 3 0.0 786849463
primitive 4 0.0 1029222237
primitive 5 0.0 1870182218
primitive 6 0.0 1057545785
primitive 7 0.0 715242967
primitive 8 0.0 2199834847
primitive 9 0.02 1807882550
primitive 10 0.33 1762503395
primitive 11 3.64 1288653164
primitive 12 47.8 1846804445
primitive 13 657.54 1903263890
dp 1 0.0 0
dp 2 0.0 1409702067
dp 3 0.0 786849463
dp 4 0.0 1029222237
dp 5 0.0 1870182218
dp 6 0.0 1057545785
dp 7 0.0 715242967
dp 8 0.0 2199834847
dp 9 0.0 1807882550
dp 10 0.0 1762503395
dp 11 0.0 1288653164
dp 12 0.01 1846804445
dp 13 0.03 1903263890
dp 14 0.03 1941672747
dp 15 0.05 1414527526
dp 16 0.13 1130708006
dp 17 0.27 1740657228
dp 18 0.65 1829633561
dp 19 1.47 1674823634
dp 20 3.06 1309957975
dp 21 6.74 1533473480
dp 22 15.22 1478354492
dp 23 31.27 1395129776
dp 24 76.51 1610342451
dp 25 146.57 1716254657
primitive_optimized 1 0.0 0
primitive_optimized 2 0.0 1409702067
primitive_optimized 3 0.0 786849463
primitive_optimized 4 0.0 1029222237
primitive_optimized 5 0.0 1870182218
primitive_optimized 6 0.0 1057545785
primitive_optimized 7 0.0 715242967
primitive_optimized 8 0.0 2199834847
primitive_optimized 9 0.0 1807882550
primitive_optimized 10 0.02 1762503395
primitive_optimized 11 0.2 1288653164
primitive_optimized 12 2.57 1846804445
primitive_optimized 13 33.94 1903263890
primitive_optimized 14 348.14 1941672747
```
