FROM gcc:latest
WORKDIR /usr/src/app 
COPY ./src/ .
RUN g++ -o bloomFilter ./main.cpp ./bloomFilter.cpp
#add after ./main.cpp every class file we need to include
CMD ["./bloomFilter"]