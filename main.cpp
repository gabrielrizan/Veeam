#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;
using std::vector;
using std::string;
using std::ifstream, std::ofstream;

int main() {
    vector<string> files_source;
    vector<string> files_destination;
    string path_to_src_dir = "/Users/mymacbook/CLionProjects/Veeam/source";
    string path_to_dst_dir = "/Users/mymacbook/CLionProjects/Veeam/replica";
    bool changes_made = false;
    for (const auto& entry : fs::directory_iterator(path_to_src_dir))
    {
        string file_name = entry.path().string();
        files_source.push_back(file_name);
        file_name.replace(file_name.find("source"), 6, "replica");
        files_destination.push_back(file_name);
        changes_made = true;
    }

    //empty replica directory
    for (const auto& entry : fs::directory_iterator(path_to_dst_dir))
    {
        string file_name = entry.path().string();
        std::cout << "File deleted from replica: " << file_name << std::endl;
        remove(file_name.c_str());
        changes_made = true;
    }

    if (!changes_made) {
        std::cout << "No changes made to replica directory" << std::endl;
        return 0;
    }

    while (!files_source.empty()) {
        ifstream file_source(files_source.back());
        ofstream file_destination(files_destination.back());
        string line;
        while (getline(file_source, line))
            file_destination << line << std::endl;
        std::cout << "File added to replica: " << files_destination.back() << std::endl;
        files_source.pop_back();
        files_destination.pop_back();
    }

    return 0;
}
