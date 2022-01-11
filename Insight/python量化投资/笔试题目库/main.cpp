#include <iostream>
#include <cstring>


int encode1(unsigned _num, void*(_buffer), size_t _buf_len=-1){
    /**
     * @brief Q1 encode the positive number
     * 
     * Args:
     *      _num: the number to be encoded
     *      _buffer: the buffer to save the encode binary, if it doesn't have enough space, overflow may be caused
     *      _buf_len: An argument preset the size of the buffer, to prevent overflow
     * 
     * Returns:
     *      (int): whether the encoded is successed
     */
    char MSB = 0b00000000;
    size_t size = 0;
    int tmp = _num;
    while(tmp){
        tmp = tmp >> 7;
        if(++size>_buf_len)return -1;
    }
    do{
        char chunk = (_num & 0b01111111) | MSB; // calculate the result of chunk
        std::memcpy(_buffer+(--size), &chunk, 1);
        _num = _num >> 7;
        MSB = 0b10000000;
    }while(size);
    return 0;
}

unsigned int decode1(void* _buffer, size_t buf_len=-1){
    /**
     * @brief Q1 decode the binary in buffer to a positive number
     * 
     * Args:
     *
     *      _buffer: the buffer to save the encode binary
     *      _buf_len: An argument preset the size of the buffer to prevent infinite loop
     * 
     * Returns:
     *      (unsigned int): The decoded number
     */
    unsigned int num = 0, i=0;
    char* buf = (char*)_buffer;
    do{
        num = num << 7;
        num += buf[i] & 0b1111111;
    }while(buf[i++] & 0b10000000);
    return num;
}

int encode2(int _num, void*(_buffer), size_t _buf_len=-1){
    /**
     * @brief Q2 encode the positive and negative number by using Q1's mechanism
     * Use another byte in the buffer to save the sign of the data
     * 
     * Args:
     *      _num: the number to be encoded
     *      _buffer: the buffer to save the encode binary, if it doesn't have enough space, overflow may be caused
     *      _buf_len: An argument preset the size of the buffer, to prevent overflow
     * 
     * Returns:
     *      (int): whether the encoded is successed
     */
    char flag = (_num >> 31) << 7; // determine whether the number is smaller than 0
    memset(_buffer, flag, 1); // use another byte to save the sign of the data
    if(flag)_num=-_num;
    return encode1(_num, _buffer + 1, _buf_len);
}

int decode2(void* _buffer, size_t buf_len=-1){
    /**
     * @brief Q2 decode the binary in buffer to a negative or positive number based on Q1's mechanism
     * 
     * Args:
     *
     *      _buffer: the buffer to save the encode binary
     *      _buf_len: An argument preset the size of the buffer to prevent infinite loop
     * 
     * Returns:
     *      (int): The decoded number
     */
    char* buf = (char*)_buffer;
    char flag = buf[1];
    int num = decode1(_buffer+1);
    if(flag)num = -num;
    return num;
}


int test(){
    char * buffer1 = (char*)std::malloc(10);
    char * buffer2 = (char*)std::malloc(10);
    memset(buffer1, 0, 10);
    memset(buffer2, 0, 10);

    encode1(558, buffer1, 10);
    printf("%hhx\n", buffer1[0]);
    printf("%hhx\n", buffer1[1]);
    printf("%d\n", decode1(buffer1));


    encode2(-558, buffer2, 10);
    printf("%hhx\n", buffer2[0]);
    printf("%hhx\n", buffer2[1]);
    printf("%hhx\n", buffer2[2]);
    printf("%d", decode2(buffer2));

    free(buffer1);
    free(buffer2);
    return 0;
}

int main(int argc, char* argv[]){
    test();
    return 0;
}