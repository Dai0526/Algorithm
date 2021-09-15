from Vehicle.VehicleBase import VehicleBase

from TeslaFactory.VehicleFactoryBase import VehicleFactoryBase
from TeslaFactory.SUVFactoryLongLast import SUVFactoryLongLast
from TeslaFactory.SUVFactoryPerformance import SUVFactoryPerformance

class VehicleFactory(VehicleFactoryBase):

    def create_SUV(self, model, type) -> VehicleBase:
        factory = None
        if type.lower() == "performance":
            factory = SUVFactoryPerformance()
        elif type.lower() == "longrange":
            factory = SUVFactoryLongLast()

        car = None
        if model == "modelx":
            car = factory.create_model_x()
        elif model == "modely":
            car = factory.create_model_y()
        return car

    def create_Sedan(self, model, type) -> VehicleBase:
        print("Not Implemented\r\n")
        return None

