#include "Icommand.h"
#include <string>
#include"addUrl.h"


//constructor
addUrl::addUrl(BloomFilter* bloomFilter) {
    this->bloomFilter = bloomFilter;
}
        
// Add URL to the bloom filter
void addUrl::execute(std::string& url){
    //Add the URL to the black list
    add_to_black_list(url);
    // Add the URL to the bit array filter
    add_to_bit_array(url);
};
   

// Add URL to the black list
void addUrl::add_to_black_list(std::string& url) {
    bloomFilter->get_black_list().push_back(url);
}

// Add URL to the bit array
void addUrl::add_to_bit_array(std::string& url){
        size_t index = bloomFilter->get_hFunc1().activateFunction(url);
        //set the bit to true
        bloomFilter->get_bit_array()[index % bloomFilter->get_bit_array().size()] = true;
        //check if the second hash function is set
        if(bloomFilter->get_hFunc2Flag()){
            //set the bit to true
            index = bloomFilter->get_hFunc2().activateFunction(url);
            bloomFilter->get_bit_array()[index % bloomFilter->get_bit_array().size()] = true;
        } 
 }
