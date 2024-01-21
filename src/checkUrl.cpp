#include "Icommand.h"
#include <string>
#include "bloomFilter.h"
#include <iostream>
#include "checkUrl.h"

class checkUrl : public Icommand {
    public:
        //constructor
        checkUrl(BloomFilter* bloomFilter) {
            this->bloomFilter = bloomFilter;
        }

        void execute(std::string& url)override{
            check_url(url);
        }

    private:
        BloomFilter* bloomFilter;  

        // Check if the URL is in the bit array
    bool is_on_bit_array(std::string& url){

        size_t index = bloomFilter->get_hFunc1().activateFunction(url);
        std::vector<bool>& bit_array = bloomFilter->get_bit_array();

        //check if the bit is true
        if(bit_array[index % bit_array.size()]){
            //check if the second hash function is on
            if(bloomFilter->get_hFunc2Flag()){  
                index = bloomFilter->get_hFunc2().activateFunction(url);
                //check if the bit is true
                if(bit_array[index % bit_array.size()]){
                    return true;
                }
            return false;
            }
            return true;
        }
        return false;
    }

    // Check if the URL is in the black list
    bool is_on_black_list(std::string& url) {
        std::vector<std::string>& black_list = bloomFilter->get_black_list();
        //check if the url is in the black list
        return std::find(black_list.begin(), black_list.end(),url) != black_list.end();
    }

    // Check if the URL is blacklisted
    void check_url(std::string& url){
        if(this->is_on_bit_array(url)){
            std::cout << "true " ;
        }
        else{
            std::cout << "false" << std::endl;;
            return;
        }
        if(this->is_on_black_list(url)){
            std::cout << "true" << std::endl;   
        }
        else{
            std::cout << "false" << std::endl;;
        }
    }
};