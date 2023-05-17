using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace StringOperations
{
    public class ABC
    {
        public string Letters { get; private set; }
        public int[] DigitValues { get; private set; }

        public int Base { get; private set; }

        public ABC(string letters)
        {
            Letters = "@" + letters;
            DigitValues = new int[Letters.Length];
            for (int i = 0; i < DigitValues.Length; i++)
            {
                DigitValues[i] = i;
            }
            Base = DigitValues.Length;
        }
        public int GetDigitValueFromChar(char c)
        {
            if (Letters.IndexOf(c) == -1)
            {
                Console.WriteLine("{0} wasn't found in {1}",c,Letters);
            }
            return DigitValues[Letters.IndexOf(c)];
        }

        public char GetCharFromDigit(BigInteger number)
        {
            for (int i = 0; i < DigitValues.Length; i++)
            {
                if (DigitValues[i] == number)
                {
                    return Letters[i];
                }
            }
            return '@';
        }

        public string GetStringFromDigits(List<BigInteger> numbers)
        {
            string result = "";
            for (int i = 0; i < numbers.Count; i++)
            {
                result += GetCharFromDigit(numbers[i]);
            }
            return result;
        }

        public string GetStringFromDigitsBackwards(List<BigInteger> numbers)
        {
            string result = "";
            for (int i = numbers.Count - 1; i >= 0; i--)
            {
                result += GetCharFromDigit(numbers[i]);
            }
            return result;
        }

        public static string GenerateABC(string text)
        {
            HashSet<char> letters = new HashSet<char>();
            for (int i = 0; i < text.Length; i++)
            {
                letters.Add(text[i]);
            }
            letters.Remove('@');
            char[] abc = letters.ToArray();
            Array.Sort(abc);
            return new string(abc.ToArray());
        }
    }
}
