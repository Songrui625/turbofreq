# turbofreq
turbofreq is a better tool to get the all-cores turbo frqeuency with diffrerent instruction workload

# Why
With different intel processor, different instruction will make cpu core run in a different turbo frequency, which is invisable to programmer. Turbofreq could help you get all-cores turbo frequency with different number of active cores in different instruction workload.

# Supported platforms
Linux

**note**: Turbofreq is not worked in virtual machine unable to read frequency

# Get started
```bash
make -C workload
chmod +x turbofreq
taskset -c 0 ./turbofreq
```

