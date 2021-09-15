from abc import ABC, abstractmethod
from Vehicle.VehicleBase import VehicleBase

class VehicleFactoryBase(ABC):

    @abstractmethod
    def create_Sedan(self, model, type) -> VehicleBase:
        pass
    
    @abstractmethod
    def create_SUV(self, model, type) -> VehicleBase:
        pass