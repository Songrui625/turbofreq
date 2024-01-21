all: matmul_sse matmul_avx matmul_avx512

matmul_sse:
	g++ -O2 -msse -ffast-math matmul_sse.cc -o matmul_sse

matmul_avx:
	g++ -O2 -mavx -ffast-math matmul_avx.cc -o matmul_avx

matmul_avx512:
	g++ -O2 -mavx512f --fast-math matmul_avx512.cc -o matmul_avx512

clean:
	rm -rf matmul_sse
	rm -rf matmul_avx
	rm -rf matmul_avx512
