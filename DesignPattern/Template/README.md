# Template Method

The template defines the **skeleton** or **steps** of an algorithm , but allowing subclasses to **define parts of an algorithm without modifying the overall structure of the algorithm.**

* Factors out the common code among its subclasses and puts them into the abstract class. 
* The variable parts of the algorithm are left for the subclasses to override. 
* The ordering of the steps is fixed by the abstract class.

Usually, the algorithm is represented as a *series of methods* which are then invoked in the desired sequence in another method. Note that the classes may choose to ignore overriding certain steps or choose to rely on the default implementation provided by the abstract class. The abstract class may want to forbid the subclasses from overriding behavior for some steps, it can enforce this constraint by marking the methods implementing those steps as `final`.  

### Pros 
1. Reuseable and scalable
    1. Supress duplicate code into a superclass
    2. Clients override only certain parts of a large algorithm, making them less affected by changes that happen to other parts of the algorithm.
2. Robustness
    1. Higher level components don't depend on lower level components and call the lower level components as and when required. 

### Cons
1. Template methods tend to be harder to maintain the more steps they have.

When entities at various levels depend horizontally and vertically on various other entities, it becomes what is called a `Dependency Rot`. The pattern helps avoid the dependency rot by making the lower level components (subclasses) depend on the higher level abstract class.



### Caveats
* **Strategy pattern** uses composition by accepting objects that define the entire algorithm, whereas the template pattern method uses inheritance to vary parts of the algorithm by subclasses but the outline and structure of the algorithm is still the realm of the abstract class.

* **Factory method** pattern is a specialization of the template method pattern.

* **Interface** The number of methods for which the subclasses need to provide implementation should be minimized when applying the template method pattern.

## Demo

### Output
```
Run Scout Recon
Step 1: Loaded Scan Parameters
Step 2: Loaded Configuration
Step 3: Loaded Data
Step 4 (overrided): Set Geomtry for Scout Recon
Step 5: Create Agent
        Create Prep Agent
        Create Rebin Agent
        Create BP Agent
Step 6: Start Agent to do Reconstruction
Step 7: Image Saved

Run Axial Recon
Step 1: Loaded Scan Parameters
Step 2: Loaded Configuration
Step 3: Loaded Data
Step 4 (overrided): Set Geomtry for Axial Recon
Step 5 (overrided): Create Agent
        Create Prep Agent
        Create Rebin Agent
        Create BP Agent
        Create Bone Correction Agent
Step 6: Start Agent to do Reconstruction
Step 7: Image Saved

Run Helical Reocn
Step 1: Loaded Scan Parameters
Step 2: Loaded Configuration
Step 3: Loaded Data
Step 4 (overrided): Set Geomtry for Helical Recon
Step 5 (overrided): Create Agent
        Create Prep Agent
        Create Fixframe Agent
        Create Rebin Agent
        Create BP Agent
        Create Bone Correction Agent
Step 6: Start Agent to do Reconstruction
Step 7: Image Saved
```