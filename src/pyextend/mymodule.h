#include <numeric>
#include <string>
#include <vector>

int Add(int a, int b) { return a + b; }

int Sum(const std::vector<int> &v) {
  return std::accumulate(v.begin(), v.end(), 0);
}

std::string Reverse(const std::string &s) {
  return std::string(s.rbegin(), s.rend());
}

struct Person {
  Person(const std::string &name, uint8_t age,
         const std::string &address = "earth")
      : name(name), age(age), address(address) {}

  const std::string &GetName() const { return name; }

  std::string name;
  uint8_t age;
  std::string address;
};
