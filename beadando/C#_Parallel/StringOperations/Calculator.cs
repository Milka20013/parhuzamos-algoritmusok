using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace StringOperations
{
    public class Calculator
    {
        private ABC abc;
        private BigInteger[] powers;
        public Calculator(ABC abc, int longestWordLength)
        {
            this.abc = abc;
            powers = new BigInteger[longestWordLength];
            CalculatePowers();
        }

        private void CalculatePowers()
        {
            powers[0] = 1;
            for (int i = 1; i < powers.Length; i++)
            {
                powers[i] = powers[i - 1] * abc.Base;
            }
        }

        public BigInteger GetNumberForm(string strForm)
        {
            BigInteger result = new BigInteger();
            for (int i = 0; i < strForm.Length; i++)
            {
                result += abc.GetDigitValueFromChar(strForm[i]) * powers[strForm.Length - i -1];
            }
            return result;
        }

        public string GetStringForm(BigInteger numberForm)
        {
            BigInteger number = numberForm;
            List<BigInteger> results = new List<BigInteger>();
            do
            {
                number = BigInteger.DivRem(number, abc.Base, out BigInteger remainder);
                results.Add(remainder);
            } while (number != 0);
            return abc.GetStringFromDigitsBackwards(results);
        }

        public string Add(BigInteger numberForm1, BigInteger numberForm2)
        {
            return GetStringForm(numberForm1 + numberForm2);
        }

        public string Add(string strForm1, string strForm2)
        {
            return Add(GetNumberForm(strForm1), GetNumberForm(strForm2));
        }

        public string Substract(BigInteger numberForm1, BigInteger numberForm2)
        {
            if (BigInteger.Compare(numberForm1,numberForm2) <= 0)
            {
                return "@";
            }
            return GetStringForm(numberForm1 - numberForm2);
        }

        public string Substract(string strForm1, string strForm2)
        {
            return Substract(GetNumberForm(strForm1), GetNumberForm(strForm2));
        }
        public string Divide(BigInteger numberForm1, BigInteger numberForm2)
        {
            if (numberForm2.IsZero)
            {
                return "@";
            }
            return GetStringForm(numberForm1 / numberForm2);
        }

        public string Divide(string strForm1, string strForm2)
        {
            return Divide(GetNumberForm(strForm1), GetNumberForm(strForm2));
        }

        public string Modulo(BigInteger numberForm1, BigInteger numberForm2)
        {
            return GetStringForm(numberForm1 % numberForm2);
        }

        public string Modulo(string strForm1, string strForm2)
        {
            return Modulo(GetNumberForm(strForm1), GetNumberForm(strForm2));
        }

        public string Multiply(BigInteger numberForm1, BigInteger numberForm2)
        {
            return GetStringForm(numberForm1 * numberForm2);
        }

        public string Multiply(string strForm1, string strForm2)
        {
            return Multiply(GetNumberForm(strForm1), GetNumberForm(strForm2));
        }


    }
}
