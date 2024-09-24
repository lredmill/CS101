#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> ExtractStringDataFromFile(std::string filename)
{
    std::vector<std::string> file_data;
    std::ifstream file_reader;
    file_reader.open(filename);
    if (!file_reader.is_open())
    {
        std::cerr << "The input file: " << filename << " does not exist" << std::endl;
        return file_data;
    }


    std::string line;
    while(std::getline(file_reader, line))
    {
        file_data.push_back(line);
    }
    file_reader.close();
    return file_data;
}

std::vector<int> FlattenIntData(std::vector<std::string> raw_data)
{
    std::vector<int> flat_vector;
    //loop through each vector of string data and perform the correct operation to:
    //1.) Parse each line based on whitespace
    //2.) Convert each parsed string to an int (hint stoi)
    //3.) Push each int into the flattened vector initialized abovce
    for (auto& raw_datum : raw_data)
    {
        //Create a subroutine that parses each line in the vector by whitespace
        //You may want to convert these values to int in the same subroutine 
        //(i.e. return  a vector<int>)

        //Create another loop that loops through each int in this localized vector
        //Push it to flat_vector.
    }

    //Create and call a subroutine that orders flat_vector into ascending order
    //I think your prof mentioned he wrote this for you?

    //Create a another subroutine that removes repeat entries
    return flat_vector;
}

std::vector<std::string> FlattenStringData(std::vector<std::string> raw_data)
{
    std::vector<std::string> flat_vector;
    //loop through each vector of string data and perform the correct operation to:
    //1.) Parse each line based on whitespace
    //2.) Push each string into the flattened vector initialized abovce
    for (auto& raw_datum : raw_data)
    {
        //Create a subroutine that parses each line in the vector by whitespace
 
        //Create another loop that loops through each int in this localized vector
        //Push it to flat_vector.
    }

    //Create and call a subroutine that orders flat_vector into lexagraphical order
    //This might be complicated, try to find an algorithm than writing your own.
    //I think your prof mentioned he wrote this for you?

    //Create a another subroutine that removes repeat entries
    return flat_vector;
}

void CompareData(std::vector<int> int_data_1, std::vector<int> int_data_2)
{
    for (auto& int_datum_1 : int_data_1)
    {
        for (auto& int_datum_2 : int_data_2)
        {
            if (int_datum_1 == int_datum_2)
            {
                std::cout << int_datum_1 << std::endl;
            }
        }
    }
}

void CompareData(std::vector<std::string> string_data_1, std::vector<std::string> string_data_2)
{
    for (auto& string_datum_1 : string_data_1)
    {
        for (auto& string_datum_2 : string_data_2)
        {
            if (string_datum_1 == string_datum_2)
            {
                std::cout << string_datum_1 << std::endl;
            }
        }
    }
}

void PrintRawData(std::vector<std::string> dataset)
{
    for (auto& datum : dataset)
    {
        std::cout << datum << std::endl;
    }
}

int main(int argc, char* argv[]) {

    // Ensure the correct number of arguments (1 for program name, 3 for the arguments)
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " arg1 arg2 arg3" << std::endl;
        return 1;
    }

    std::string sort_option = argv[1];
    std::string file_1 = argv[2];
    std::string file_2 = argv[3];

    //Extract data in each file as a vector of strings, line by line
    std::vector<std::string> dataset_1 = ExtractStringDataFromFile(file_1);
    std::vector<std::string> dataset_2 = ExtractStringDataFromFile(file_2);

    //Print data just to prove you read it. You may delete these calls later
    PrintRawData(dataset_1);
    PrintRawData(dataset_2);
    if (sort_option=="i")
    {
        std::cout << "This is the integer sorting algorithm" << std::endl;

        //Get a flat, ordered vector of int data from raw string data. No repeats.
        std::vector<int> int_data_1 = FlattenIntData(dataset_1);
        std::vector<int> int_data_2 = FlattenIntData(dataset_2);
        //This could be templated and moved outside of these conditionals
        CompareData(int_data_1, int_data_2);
        
    }
    else if (sort_option=="s")
    {
        std::cout << "This is the string sorting algorithm" << std::endl;
        //Get a flat, ordered vector of string data from raw string data. No repeats.
        std::vector<std::string> string_data_1 = FlattenStringData(dataset_1);
        std::vector<std::string> string_data_2 = FlattenStringData(dataset_2);
        CompareData(string_data_1, string_data_2);
    }

    // Create a vector to store the arguments
    std::vector<std::string> args;

    // Push command line arguments (argv[1] to argv[3]) to the vector
    for (int i = 1; i < argc; ++i) {
        args.push_back(argv[i]);
    }

    // Output the vector contents to confirm the arguments are stored
    std::cout << "Stored arguments:" << std::endl;
    for (const std::string& arg : args) {
        std::cout << arg << std::endl;
    }

    return 0;
}
