#include <iostream>
#include <fstream>

const std::string kTestFile = "./test_data/praxix.z5";

std::pair<std::unique_ptr<uint8_t>, std::streampos> ReadFile(const std::string& file_name) {
  std::ifstream file(file_name, std::ios::binary);

  file.seekg(0, std::ios::end);

  auto file_size = file.tellg();

  file.seekg(0, std::ios::beg);

  auto buffer = std::make_unique<uint8_t>(file_size);

  file.read(reinterpret_cast<char*>(buffer.get()), file_size);

  return std::make_pair(std::move(buffer), file_size);
}

int main(int, char*[]) {

  auto [buffer, file_size]  = ReadFile(kTestFile);

  std::cout << "Read " << kTestFile << ", size = " << file_size << std::endl;

  return 0;
}
