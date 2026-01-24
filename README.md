### **Laboratorium 8: Wzorce kreacyjne (Creational Patterns) w programowaniu obiektowym**

---

### **Cel laboratorium**

Poznanie i praktyczne zastosowanie **wzorów kreacyjnych** w programowaniu obiektowym. W trakcie zajęć studenci nauczą się, jak tworzyć obiekty w sposób elastyczny i kontrolowany, przy użyciu wzorców takich jak **Singleton**, **Factory Method**, **Abstract Factory**, **Builder** oraz **Prototype**. 

Celem laboratorium jest wprowadzenie studentów do **wzorów kreacyjnych** w programowaniu obiektowym, które są używane do kontrolowania i optymalizowania procesu tworzenia obiektów. Studenci nauczą się:
1. Rozpoznawać sytuacje, w których zastosowanie wzorców kreacyjnych przynosi korzyści.
2. Implementować wzorce takie jak **Singleton**, **Factory Method**, **Builder** w językach **Java** i **C++**.
3. Zrozumieć, w jaki sposób wzorce te wspierają projektowanie modularnych i skalowalnych systemów.

---

### **Zakres tematyczny**

Laboratorium obejmuje następujące wzorce kreacyjne:
1. **Singleton** – Gwarantuje istnienie tylko jednej instancji klasy i umożliwia globalny dostęp do niej.
2. **Factory Method** – Umożliwia tworzenie obiektów bez ujawniania konkretnej klasy obiektu.
3. **Builder** – Ułatwia tworzenie złożonych obiektów przez rozdzielenie procesu konstrukcji od finalnej reprezentacji.
4. **Prototype** – Tworzy nowe obiekty poprzez klonowanie istniejących.

---

### **Efekty kształcenia**

Po ukończeniu laboratorium studenci:
1. Zrozumieją znaczenie wzorców kreacyjnych w procesie projektowania oprogramowania.
2. Nauczą się implementować wybrane wzorce w językach **Java** i **C++**.
3. Będą potrafili wybrać odpowiedni wzorzec kreacyjny dla konkretnego problemu w projekcie.
4. Docenią elastyczność, którą wzorce te wprowadzają do projektowania systemów.

---

### **Przegląd wzorców kreacyjnych**

1. **Singleton**  
   Gwarantuje istnienie tylko jednej instancji klasy w aplikacji i zapewnia globalny dostęp do niej.

2. **Factory Method**  
   Definiuje interfejs tworzenia obiektu, pozwalając podklasom decydować, jaki obiekt utworzyć.

3. **Abstract Factory**  
   Umożliwia tworzenie rodzin powiązanych obiektów bez określania ich konkretnych klas.

4. **Builder**  
   Rozdziela konstrukcję złożonego obiektu od jego reprezentacji, umożliwiając tworzenie różnych reprezentacji.

5. **Prototype**  
   Tworzy nowe obiekty poprzez klonowanie istniejących obiektów.

---

### **Praktyczne zastosowanie wzorców kreacyjnych**

1. **Singleton**: 
   - Używany w systemach zarządzających zasobami, np. połączeniami z bazą danych, rejestratorami logów.
   - Zaleta: gwarancja jednej instancji.
2. **Factory Method**: 
   - Sprawdza się w sytuacjach, gdy klasa bazowa definiuje metodę tworzenia obiektów, ale decyzja o tym, jaka klasa zostanie utworzona, należy do podklasy.
3. **Builder**:
   - Idealny do tworzenia złożonych obiektów, np. konfiguracji użytkownika, pojazdów z opcjonalnymi elementami.
4. **Prototype**:
   - Pomocny w sytuacjach, gdy tworzenie obiektów jest kosztowne, a klonowanie istniejących instancji pozwala na oszczędność zasobów.

---

### **Zadania**

---

#### **Zadanie 1: Implementacja wzorca Singleton**

**Opis:**  
Utwórz klasę zarządzającą połączeniem z bazą danych, która zapewnia, że istnieje tylko jedna instancja tej klasy.

##### **Java**
```java
class DatabaseConnection {
    

    private DatabaseConnection() {
        
    }

    public static DatabaseConnection getInstance() {
     
    }

    public void executeQuery(String query) {
       
    }
}

public class Main {
    
}
```

##### **C++**
```cpp
#include ...

class DatabaseConnection {

public:
    static DatabaseConnection* getInstance() {
      
};

int main() {
    
    cout << "Czy obie instancje są takie same? " << (connection1 == connection2) << endl;

    return 0;
}
```

---

#### **Zadanie 2: Implementacja wzorca Factory Method**

**Opis:**  
Utwórz system tworzenia różnych typów pojazdów (np. samochodów i rowerów) za pomocą metody fabrycznej.

##### **Java**
```java
abstract class Vehicle {
   
}

class Car extends Vehicle {
    
}

class Bike extends Vehicle {
  
}

class VehicleFactory {
  
}

public class Main {
    public static void main(String[] args) {
  
}
```

##### **C++**
```cpp
#include ...

class Vehicle {

};

class Car : public Vehicle {

};

class Bike : public Vehicle {

};

class VehicleFactory {

};

int main() {
   
}
```

---

#### **Zadanie 3: Implementacja wzorca Builder**

**Opis:**  
Utwórz klasę do budowania różnych wariantów pizzy, takich jak Margarita lub Pepperoni.

##### **Java**
```java
class Pizza {
  
    private Pizza(PizzaBuilder builder) {
        
    }

    public static class PizzaBuilder {
        

        public PizzaBuilder dough(String dough) {
           
        }

        public PizzaBuilder sauce() {
           
        }

        public PizzaBuilder topping() {
           
        }

        public Pizza build() {

    }

    @Override
  
}

public class Main {
    public static void main(String[] args) {

        System.out.println(pizza);
    }
}
```

##### **C++**
```cpp
#include ...

class Pizza {

public:
    class Builder {
   
    public:
        Builder& setDough() {
          
        }

        Builder& setSauce() {
           
        }

        Builder& setTopping() {
           
        }

        Pizza build() {
          
        }
    };

    
    void display() const {
        
    }
};

int main() {
    
    return 0;
}
```

---

### **Podsumowanie**

Podczas laboratorium studenci:
1. Poznają podstawowe wzorce kreacyjne i ich zastosowanie.
2. Zrozumieją różnice między wzorcami i w jakich sytuacjach należy je stosować.
3. Stworzą przykłady kodu w **Java** i **C++**, co pogłębi ich zrozumienie wzorców kreacyjnych.

### **Podsumowanie**

Laboratorium pozwala studentom zrozumieć, jak wzorce kreacyjne wpływają na:
1. **Modularność** – Możliwość łatwej modyfikacji systemu bez zmiany jego podstawowych komponentów.
2. **Skalowalność** – Łatwiejsze dostosowanie systemu do zmieniających się wymagań.
3. **Efektywność kodu** – Optymalizacja procesu tworzenia obiektów.

Dzięki praktycznym zadaniom w językach **Java** i **C++**, studenci nauczą się stosować te wzorce w rzeczywistych projektach. Laboratorium to jest fundamentem do dalszego zgłębiania wzorców projektowych i ich zastosowań w zaawansowanych systemach.
