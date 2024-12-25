import tkinter as tk
import serial

# Configuração da porta serial
arduino = serial.Serial('COM3', 9600)  # Ajuste para a porta correta

def send_command(command):
    """Envia comandos para o Arduino."""
    arduino.write(command.encode())

def on_close():
    """Fecha a aplicação e a conexão serial."""
    arduino.close()
    root.destroy()

# Janela principal
root = tk.Tk()
root.title("Controlador Arduino")
root.geometry("300x300")

# Botões para os comandos
btn_up = tk.Button(root, text="↑", command=lambda: send_command('U'), width=10, height=2)
btn_down = tk.Button(root, text="↓", command=lambda: send_command('D'), width=10, height=2)
btn_left = tk.Button(root, text="←", command=lambda: send_command('L'), width=10, height=2)
btn_right = tk.Button(root, text="→", command=lambda: send_command('R'), width=10, height=2)
btn_pgup = tk.Button(root, text="Saltar (PgUp)", command=lambda: send_command('P'), width=15, height=2)
btn_pgdn = tk.Button(root, text="Abaixar (PgDn)", command=lambda: send_command('N'), width=15, height=2)

# Layout dos botões
btn_up.grid(row=0, column=1)
btn_left.grid(row=1, column=0)
btn_down.grid(row=1, column=1)
btn_right.grid(row=1, column=2)
btn_pgup.grid(row=2, column=0, columnspan=3)
btn_pgdn.grid(row=3, column=0, columnspan=3)

# Configura o fechamento da janela
root.protocol("WM_DELETE_WINDOW", on_close)

# Inicia o loop da interface gráfica
root.mainloop()
