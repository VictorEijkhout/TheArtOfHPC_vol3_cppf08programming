// based on page 153 of Davidson book

class commander {};

class soldier {
public:
  commander& get_commander();
  commander const& get_commander() const;
private:
  static commander _c;
  template<class T>
  static auto get_commander_impl(T& t) -> decltype(t.get_commander) {
    return _c;
  };
};

int main() {
  soldier s;
  auto c = s.get_commander();
  return 0;
}
