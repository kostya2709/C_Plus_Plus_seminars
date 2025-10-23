   for (size_t i = 0; i < integer.size(); i++) {
      if (i == 0) {
        result += std::to_string(integer[integer.size() - i - 1]);
      } else {
        int number_of_nulls = number_of_digits - static_cast<int>(
                std::to_string(integer[integer.size() - i - 1]).size());
        result += std::string(number_of_nulls, '0');
        result += std::to_string(integer[integer.size() - i - 1]);
      }
    }

