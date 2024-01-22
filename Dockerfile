FROM gcc:latest
WORKDIR /usr/src/app 
COPY ./src/ .
RUN g++ -o bloomFilter ./main.cpp ./AddUrl.cpp ./App.cpp ./BloomFilter.cpp ./CheckUrl.cpp ./CommandValidator.cpp ./HFunc.cpp ./OneHashValidator.cpp ./TwoHashValidator.cpp
#add after ./main.cpp every class file we need to include
CMD ["./bloomFilter"]