 for (size_t i = 0; i < polynom.size(); ++i) {
    (i % 2 == 0 ? even.emplace_back(polynom[i]) : odd.emplace_back(polynom[i]));
 }

