from TeslaFactory.VehicleFactory import VehicleFactory

if __name__ == "__main__":

    tesla_factory = VehicleFactory()
    model_x_perf = tesla_factory.create_SUV("modelx", "performance")
    model_x_range = tesla_factory.create_SUV("modelx", "longrange")

    model_y_perf = tesla_factory.create_SUV("modely", "performance")
    model_y_range = tesla_factory.create_SUV("modely", "longrange")

    print("ModelX Performance Version: \r\n {}\r\n".format(model_x_perf.get_details()))
    print("ModelX Long Range Version: \r\n {}\r\n".format(model_x_range.get_details()))

    print("ModelY Performance Version: \r\n {}\r\n".format(model_y_perf.get_details()))
    print("ModelY Long Range Version: \r\n {}\r\n".format(model_y_range.get_details()))