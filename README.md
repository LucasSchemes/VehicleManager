# VehicleManager

Sistema de gerenciamento de veículos com foco no controle de placas, distância percorrida e consumo de combustível.

---

## ​ Descrição

O **VehicleManager** é um sistema desenvolvido em **C++** que permite:

- Registrar veículos usando **número de placa**;
- Monitorar a **distância percorrida** por cada veículo;
- Acompanhar o **consumo de combustível** ao longo do tempo.

O objetivo é oferecer uma solução simples e extensível para o gerenciamento de frotas.

---

##  Funcionalidades

- **Cadastro de veículos** por placa;
- **Registro de trajetos** (início, fim, distância percorrida);
- **Registro de abastecimentos** (quantidade de combustível, custo, quilometragem);
- **Relatórios** comparativos de consumo e distância entre veículos.

---

##  Tecnologias Utilizadas

- Linguagem: **C++**
- Build: (A definir: `CMake`, `Makefile`, ou compilação direta com `g++`)
- (Caso utilize bibliotecas específicas, listar aqui — por exemplo: SQLite, Boost, etc.)

---

##  Instalação

Clone o repositório:

```bash
git clone https://github.com/LucasSchemes/VehicleManager.git
cd VehicleManager
```

Compile o código:

- Se estiver usando g++ diretamente:
```bash
g++ -std=c++17 -o VehicleManager main.cpp
```

- Se houver CMakeLists.txt, você pode compilar com:
```bash
mkdir build
cd build
cmake ..
make
```

# Execução
- Execute o binário gerado:
```bash
./VehicleManager
```
