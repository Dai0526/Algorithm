from abc import ABC, abstractmethod
from Vehicle.ModelX import ModelX
from Vehicle.ModelY import ModelY

class SUVFactoryBase(ABC):

    @abstractmethod
    def create_model_x(self) -> ModelX:
        pass

    @abstractmethod
    def create_model_y(self) -> ModelY:
        pass