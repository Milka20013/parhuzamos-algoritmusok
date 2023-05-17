using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace StringOperations
{
    public class StringN
    {
        public string str;
        public static Calculator calculator;
        public StringN(string str)
        {
            this.str = str;
        }
        public static implicit operator StringN(string s)
        {
            return new StringN(s);
        }
        public static StringN operator +(StringN a, StringN b)
            => new StringN(calculator.Add(a.str, b.str));
        public static StringN operator -(StringN a, StringN b)
            => new StringN(calculator.Substract(a.str, b.str));
        public static StringN operator *(StringN a, StringN b)
            => new StringN(calculator.Multiply(a.str, b.str));
        public static StringN operator /(StringN a, StringN b)
            => new StringN(calculator.Divide(a.str, b.str));
        public static StringN operator %(StringN a, StringN b)
            => new StringN(calculator.Modulo(a.str, b.str));

        public override string ToString()
        {
            return str;
        }

        public BigInteger NumberForm()
        {
            return calculator.GetNumberForm(str);
        }

    }
}
