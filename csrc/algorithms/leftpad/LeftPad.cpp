#include <iostream>

std::string leftPad(int i_padding = 0, std::string s_text = "")
{
    size_t length = s_text.length();

    if (length < i_padding)
        s_text.insert(0, i_padding - length, ' ');  // TODO: change to faster implementation of the insert method

    return s_text;
}

int main()
{
    int i_padding = 100;
    std::string s_pad_string = "padding_test";

    std::string s_padded_text = leftPad(i_padding, s_pad_string);

    std::cout << "s_padded_text: \n" << std::endl;
    std::cout << s_padded_text << std::endl;

    return 0;
}