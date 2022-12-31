//
//  main.cpp
//  Serialization
//
//  Created by Ризван Зайдуллин on 21.12.2022.
//

#include <iostream>
#include <fstream>

struct Connection {
    uint32_t from;
    uint32_t to;
    uint16_t weight;
};

void serialization(std::string input_path, std::string output_path) {
    std::uint32_t from, to;
    std::uint16_t weight;
    std::string tmp;
    
    std::ifstream in(input_path, std::ios_base::in);
    std::ofstream out(output_path, std::ios_base::binary);

    while (in.good()) {
        in >> from >> to >> weight;
        // if (!in.good()) break;
        // std::cout << from << " " << to << " " << weight << std::endl;
        out.write(reinterpret_cast<char *>(&from), sizeof(from));
        out.write(reinterpret_cast<char *>(&to), sizeof(to));
        out.write(reinterpret_cast<char *>(&weight), sizeof(weight));
    }

    in.close();
    out.close();

}

void deserialization(std::string input_path, std::string output_path) {
    std::uint32_t val = 700425600;
    std::uint32_t from, to;
    std::uint16_t weight;
    std::string tmp;
    
    std::ifstream in(input_path, std::ios_base::binary);
    std::ofstream out(output_path, std::ios_base::out);
    
    while (in.good()) {
        in.read(reinterpret_cast<char *>(&from), sizeof(from));
        if (!in.good()) break;
        in.read(reinterpret_cast<char *>(&to), sizeof(to));
        in.read(reinterpret_cast<char *>(&weight), sizeof(weight));
        out << from << " " << to << " " << weight << "\n";
    }

    in.close();
    out.close();

}

int main(int argc, const char * argv[]) {
    // std::cout<<argc<<std::endl;
    if (argc != 6) {
        std::cout << "Number of arguments is wrong!" << std::endl;
        return 0;
    }

    // for (int i = 0; i < argc; ++i) {
    //     std::cout<<argv[i]<<std::endl;
    // }

    if (strcmp(argv[1], "-s") == 0) {
        std::cout << "serialization" << std::endl;
        serialization(argv[3], argv[5]);
    }
    else if (strcmp(argv[1], "-d") == 0) {
        std::cout << "deserialization" << std::endl;
        deserialization(argv[3], argv[5]);
    }
    
    
    return 0;
}
