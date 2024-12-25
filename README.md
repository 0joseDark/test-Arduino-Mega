# test-Arduino-Mega
 testar o Arduino-Mega
 Aqui está uma solução em duas partes: um script em C++ para o Arduino Mega e um script em Python para criar a interface gráfica no Windows 10.

### Script em C++ para o Arduino Mega

Este script configura 7 portas do Arduino como entradas e 6 portas como saídas para controlar os LEDs. O Arduino Mega recebe comandos pela porta serial e aciona os LEDs correspondentes.

### Explicação dos Scripts

1. **Arduino Mega (C++):**
   - Define 6 portas para LEDs como saídas e 7 portas como entradas para testes futuros.
   - Recebe comandos pela porta serial e aciona os LEDs correspondentes.
   - Cada comando é identificado por uma letra (`U`, `D`, `L`, `R`, `P`, `N`).

2. **Python (Tkinter):**
   - Cria uma interface gráfica com botões para setas e ações (`PgUp` e `PgDn`).
   - Envia comandos para o Arduino ao pressionar os botões.
   - Inclui um sistema para fechar corretamente a conexão serial ao encerrar a aplicação.

Teste os scripts, ajustando a porta COM no Python para a correspondente ao Arduino Mega.

