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
