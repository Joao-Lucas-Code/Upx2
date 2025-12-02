# 🗑️ Lixeira Inteligente - Smart Waste Management

![Status](https://img.shields.io/badge/Status-Concluído-green)
![Hardware](https://img.shields.io/badge/Hardware-ESP32%20%7C%20HC--SR04-blue)
![Platform](https://img.shields.io/badge/Platform-Blynk%20IoT-success)
![Institution](https://img.shields.io/badge/Facens-Engenharia%20de%20Computação-red)

> Um projeto de IoT focado em Cidades Inteligentes e Sustentabilidade, desenvolvido para a disciplina de UPx (Usina de Projetos Experimentais).

---

## 📸 O Projeto

![Protótipo Final](images/lixeira_final.jpg)

### 🎯 O Problema
A coleta de lixo urbana tradicional é ineficiente. Caminhões percorrem rotas fixas diariamente, gastando combustível e tempo para verificar lixeiras que muitas vezes estão vazias, enquanto outras transbordam, causando problemas sanitários e má experiência para a população.

### 💡 A Solução
Desenvolvemos um dispositivo de baixo custo capaz de monitorar o nível de preenchimento de lixeiras em tempo real. Os dados são enviados via Wi-Fi para um dashboard na nuvem, permitindo que gestores otimizem rotas de coleta.

---

## 🛠️ Hardware e Componentes

| Componente | Função |
| :--- | :--- |
| **ESP32 Dev Module** | Microcontrolador com Wi-Fi integrado (Cérebro) |
| **HC-SR04** | Sensor Ultrassônico (Medição de distância) |
| **Protoboard & Jumpers** | Conexões do circuito |
| **Fonte de Energia** | Alimentação via USB (5V) |

### 🔌 Esquema de Ligação (Pinout)

![Diagrama Elétrico](images/circuito_final.jpg)

| Sensor HC-SR04 | ESP32 |
| :--- | :--- |
| **VCC** | VIN (5V) |
| **GND** | GND |
| **Trig** | GPIO 26 (D26) |
| **Echo** | GPIO 25 (D25) |

---

## 📱 Dashboard e Software

O projeto utiliza a plataforma **Blynk** para visualização de dados.

**Funcionalidades do App:**
* 📶 **Medidor em Tempo Real:** Mostra o nível de lixo em cm.
* ⚠️ **Status Dinâmico:** Informa se está "Vazia", "Quase Cheia" ou "LIXEIRA CHEIA!".
* 📊 **Conectividade:** Indicador de status online/offline.

![App Blynk](images/app_resultado.jpg)

---

## 🚀 Como Executar o Projeto

### Pré-requisitos
* Arduino IDE instalado.
* Biblioteca `Blynk` instalada na IDE.
* Drivers do ESP32 instalados.

### Instalação
1.  Clone este repositório:
    ```bash
    git clone [https://github.com/SEU_USUARIO/NOME_DO_REPO.git](https://github.com/SEU_USUARIO/NOME_DO_REPO.git)
    ```
2.  Abra o arquivo `.ino` na Arduino IDE.
3.  Instale a biblioteca **Blynk** pelo Gerenciador de Bibliotecas.
4.  Configure suas credenciais no código:
    ```cpp
    #define BLYNK_TEMPLATE_ID "SEU_ID"
    #define BLYNK_DEVICE_NAME "SEU_DEVICE"
    #define BLYNK_AUTH_TOKEN "SEU_TOKEN"
    char ssid[] = "SUA_REDE_WIFI";
    char pass[] = "SUA_SENHA";
    ```
5.  Conecte o ESP32 e faça o Upload.

---

## 👥 Autores

<table>
  <tr>
    <td align="center">
      <a href="LINK_DO_LINKEDIN_DO_ANDREW">
        <img src="https://ui-avatars.com/api/?name=Andrew+Fernandes&background=random" width="100px;" alt=""/><br>
        <sub><b>Andrew Fernandes</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="LINK_DO_LINKEDIN_DO_CAUA">
        <img src="https://ui-avatars.com/api/?name=Caua+Mendes&background=random" width="100px;" alt=""/><br>
        <sub><b>Cauã Mendes</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="LINK_DO_LINKEDIN_DO_EDUARDO">
        <img src="https://ui-avatars.com/api/?name=Eduardo+Furlanetto&background=random" width="100px;" alt=""/><br>
        <sub><b>Eduardo Furlanetto</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="LINK_DO_LINKEDIN_DO_GUILHERME">
        <img src="https://ui-avatars.com/api/?name=Guilherme+Kliman&background=random" width="100px;" alt=""/><br>
        <sub><b>Guilherme Kliman</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="LINK_DO_LINKEDIN_DO_JOAO">
        <img src="https://ui-avatars.com/api/?name=João+Lucas&background=random" width="100px;" alt=""/><br>
        <sub><b>João Lucas</b></sub>
      </a>
    </td>
  </tr>
</table>

**Orientador:** Prof. Dr. Rodrigo Henrique Geraldo

---

## 📄 Licença

Este projeto está sob a licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

---
<p align="center">Desenvolvido com 💙 por alunos da Facens</p>
