##
##

CXX	=gcc
##
## Use our standard compiler flags for the course...
## You can try changing these flags to improve performance.
##
# CXXFLAGS= -Ofast -fno-omit-frame-pointer -Wall -march="native" -mtune="native" -ftree-vectorize
## -fopt-info-vec -fopenmp
CXXFLAGS= -Wall -Wextra -O0 -g


gen_pq: gen_pq.c DataTypes.c DataTypes.h vec.c vec.h
	$(CXX) $(CXXFLAGS) -o gen_pq gen_pq.c DataTypes.c vec.c
    
gen_pq_o: gen_pq.c DataTypes.c DataTypes.h vec.c vec.h
	$(CXX) $(CXXFLAGS) -c gen_pq.c DataTypes.c vec.c

##
## Parameters for the test run
##
# FILTERS = gauss.filter vline.filter hline.filter emboss.filter
# IMAGES = boats.bmp blocks-small.bmp
# TRIALS = 1 2 3 4

#
# Run the Judge script to compute a score
#
# judge: filter
# 	./Judge -p ./filter -i blocks-small.bmp

#
# Run the Judge tests on both images and then compare the output to the reference output.
#
# Note you shouldn't use this to compute a score -- it's just for testing
#
# test:	filter
# 	./Judge -p ./filter -i boats.bmp
# 	./Judge -p ./filter -i blocks-small.bmp
# 	cmp filtered-avg-blocks-small.bmp tests/filtered-avg-blocks-small.bmp
# 	cmp filtered-avg-boats.bmp tests/filtered-avg-boats.bmp
# 	cmp filtered-emboss-blocks-small.bmp tests/filtered-emboss-blocks-small.bmp
# 	cmp filtered-emboss-boats.bmp tests/filtered-emboss-boats.bmp
# 	cmp filtered-gauss-blocks-small.bmp tests/filtered-gauss-blocks-small.bmp
# 	cmp filtered-gauss-boats.bmp tests/filtered-gauss-boats.bmp
# 	cmp filtered-hline-blocks-small.bmp tests/filtered-hline-blocks-small.bmp
# 	@echo All tests passed

clean:
	-rm -f *.o
	-rm -f gen_pq
