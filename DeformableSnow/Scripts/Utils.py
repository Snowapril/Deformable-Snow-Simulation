import os

def get_extension(abs_path):
    if os.path.isfile(abs_path):
        dot_pos = abs_path.rfind(".")
        extension = abs_path[dot_pos + 1:]
        return extension
    else:
        raise ValueError("Given argument is a incorrect file path.")

def get_all_files(dir, filter_extensions):
    if os.path.isdir(dir):
        files = []
        for file in os.listdir(dir):
            abs_path = os.path.join(dir, file)
            if os.path.isfile(abs_path) and get_extension(abs_path) in filter_extensions:
                files.append(file)
        return files
    else:
        raise ValueError("Given argument is a incorrect directory path")

def pickout_list_with_keyword(element_list, keyword):
    return [e for e in element_list if keyword in e]