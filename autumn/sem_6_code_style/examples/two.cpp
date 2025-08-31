std::string asDecimal(size_t precision = 0) const
    {
        static const int DEC_BASIS = 10;
        std::string s = (top * BigInteger(DEC_BASIS, precision) / bottom).unsign().toString();
        if (s.size() <= precision)
        {
            if (s.size() < precision)
            {
                std::string t(precision - s.size(), '0');
                s = t + s;
            }
            return (top.getSign()?"0.":"-0.") + s;        
        }
        else 
        {
            return (top.getSign()?"":"-") + s.substr(0, s.size() - precision) + 
            (precision > 0?("." + s.substr(s.size() - precision, precision)):"");
        }
    }

