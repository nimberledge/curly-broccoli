filename=$1
threads=$2

gcc -fopenmp $filename -o "${filename%.*}".out
export OMP_NUM_THREADS=$threads

./"${filename%.*}".out
