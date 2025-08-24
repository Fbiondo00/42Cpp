#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& other) : _stack(other._stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return *this;
}

// Controlla se un carattere è uno degli operatori consentiti
bool RPN::isOperator(char carattere) const
{
    return (carattere == '+' || carattere == '-' || carattere == '*' || carattere == '/');
}

// Esegue l'operazione aritmetica sui primi due elementi dello stack
void RPN::performOperation(char operatore)
{
    // Controlla che ci siano almeno 2 operandi nello stack
    if (_stack.size() < 2)
        throw std::runtime_error("Error: not enough operands for operation");

    // Estrae il primo elemento come operando destro (secondo nell'operazione)
    int operandoDestro = _stack.top();
    _stack.pop();

    // Estrae il prossimo elemento come operando sinistro (primo nell'operazione)
    int operandoSinistro = _stack.top();
    _stack.pop();

    switch (operatore)
    {
        case '+':
            _stack.push(operandoSinistro + operandoDestro);
            break;
        case '-':
            _stack.push(operandoSinistro - operandoDestro);
            break;
        case '*':
            _stack.push(operandoSinistro * operandoDestro);
            break;
        case '/':
            if (operandoDestro == 0)
                throw std::runtime_error("Error: division by zero");
            _stack.push(operandoSinistro / operandoDestro);
            break;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

int RPN::calculate(const std::string& espressione)
{
    std::istringstream iss(espressione);  // Crea uno stream per parsare l'espressione
    std::string token;

    // Processa ogni token (numero o operatore) dalla stringa di input
    while (iss >> token)
    {
        // Controlla se il token è una cifra singola (0-9)
        if (token.length() == 1 && isdigit(token[0]))
        {
            // Converte il carattere cifra in intero e lo inserisce nello stack
            _stack.push(token[0] - '0');
        }
        // Controlla se il token è uno degli operatori validi
        else if (token.length() == 1 && isOperator(token[0]))
        {
            performOperation(token[0]);
        }
        else
        {
            // Il token non è né una cifra valida né un operatore (es. numero a più cifre, parentesi, carattere non valido)
            throw std::runtime_error("Error");
        }
    }

    // Dopo aver processato tutti i token, deve esserci esattamente un valore nello stack
    // Altrimenti, l'espressione non è valida (troppi numeri o operatori insufficienti)
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");

    return _stack.top();
}
