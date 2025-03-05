#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/parse.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <yaml-cpp/yaml.h>

using json = nlohmann::json;

json yaml_to_json(const YAML::Node &yaml) {
  if (yaml.IsNull()) {
    return nullptr;
  } else if (yaml.IsScalar()) {
    return yaml.as<std::string>();
  } else if (yaml.IsSequence()) {
    json arr = json::array();

    for (const auto &el : yaml) {
      arr.push_back(yaml_to_json(el));
    }

    return arr;
  } else if (yaml.IsMap()) {
    json obj = json::object();

    for (const auto &it : yaml) {
      obj[it.first.as<std::string>()] = yaml_to_json(it.second);
    }

    return obj;
  }

  return nullptr;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <input.yaml> <output.json>\n";

    return 1;
  }

  try {
    YAML::Node yaml = YAML::LoadFile(argv[1]);

    json res = yaml_to_json(yaml);

    // Write JSON to file
    std::ofstream out_file(argv[2]);
    out_file << res.dump(2) << "\n";

    std::cout << "Conversion completed!\n";

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";

    return 1;
  }
}