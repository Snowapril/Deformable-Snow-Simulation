import inspect
import os
import configparser
import pprint

def main():
    current_path = os.path.dirname(os.path.abspath(
        inspect.getfile(inspect.currentframe())))
    root_path = os.path.join(current_path, "..")
    resource_path = os.path.join(root_path, "Resources")
	
	# Check resource dir exists, if doesnt exists create one.
    if not os.path.exists(resource_path) : os.makedirs(resource_path)

    config = configparser.ConfigParser()
    config['Common'] = {
        'root_path': '"{}"'.format(root_path),
        'log_path': r'"\Log"'
    }
    config['RenderSystem'] = {
        'window_title': '"Deforamble Snow Simulation Version 0.0.1"',
        'client_width': 1200,
        'client_height': 900,
        'default_fullscreen': 'false'
    }
    config_file_path = os.path.join(resource_path, "engine_config.ini")
    with open(config_file_path, 'w') as ini:
        config.write(ini)
    print("Generate Engine Config file Complete!")
    pprint.pprint({section : dict(config[section]) for section in config.sections()})

if __name__ == "__main__" :
    main()
