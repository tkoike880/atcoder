#include <bits/stdc++.h>

namespace pp {
  struct detail {
    std::string left = "{";
    std::string right = "}";
    std::string delim = ", ";
    std::string indent = "  ";
    bool newline = false;
    bool trailing_delim = false;
  };

  template<class CharT, class Traits>
    using Stream = std::basic_ostream<CharT, Traits>&;

  template<typename T, class CharT, class Traits>
  std::basic_ostream<CharT, Traits>& pprint_collection(
    std::basic_ostream<CharT, Traits>& stream,
    const T collection,
    const pp::detail d
  ) {
    const auto last = --collection.cend();
    stream << d.left;
    if (d.newline) stream << std::endl;
    for (auto it=collection.cbegin(); it!=last; ++it) {
      if (d.newline) stream << d.indent;
      stream << *it << d.delim;
      if (d.newline) stream << std::endl;
    }
    if (d.newline) stream << d.indent;
    stream << *last;
    if (d.trailing_delim) stream << d.delim;
    if (d.newline) stream << std::endl;
    return stream << d.right;
  }

  template<typename T1, typename T2, class CharT, class Traits>
  std::basic_ostream<CharT, Traits>& pprint_unordered_map(
    std::basic_ostream<CharT, Traits>& stream,
    const std::unordered_map<T1, T2> um,
    const pp::detail d
  ) {
    stream << d.left << std::endl;
    for (const auto& p:um) {
      stream << d.indent << p << d.delim << std::endl;
    }
    return stream << d.right;
  }
}

namespace std
{
  template<typename T, class CharT, class Traits>
  std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& stream,
    const vector<T>& v
  ) {
    return pp::pprint_collection(stream, v, pp::detail());
  }

  template<typename T, class CharT, class Traits>
  std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& stream,
    const list<T>& v
  ) {
    return pp::pprint_collection(stream, v, pp::detail("[", "]"));
  }

  template<typename T1, typename T2, class CharT, class Traits>
  std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& stream,
    const map<T1, T2>& p
  ) {
    auto d = pp::detail();
    d.newline = true;
    d.trailing_delim = true;
    return pp::pprint_collection(stream, p, d);
  }

  template<typename T1, typename T2, class CharT, class Traits>
  std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& stream,
    const unordered_map<T1, T2>& p
  ) {
    return pp::pprint_unordered_map(stream, p, pp::detail());
  }

  template<typename T1, typename T2, class CharT, class Traits>
  std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& stream,
    const pair<T1, T2>& p
  ) {
    return stream << p.first << " => " << p.second;
  }
}
